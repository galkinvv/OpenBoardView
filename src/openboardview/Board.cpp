#include "Board.h"
#include <cstdlib>
#include <cctype>


struct PinNameParseInfo {
	std::string non_digit_text;
	int digits_value_combined = 0; //index_from_Pin_number*0x10000 + index_from_Pin_name
};

static PinNameParseInfo pin_name_parse(const std::shared_ptr<Pin> &pin) {
	PinNameParseInfo result = {};
	// text from number has priority over name
	for (auto field: {&Pin::number, &Pin::name})
	{
		result.digits_value_combined *= 0x10000;
		const std::string& pin_field = *pin.*field;
		int non_digit_prefix = 0;
		for (;non_digit_prefix < static_cast<int>(pin_field.size()); ++non_digit_prefix) {
			if (isdigit(pin_field[non_digit_prefix])) {
				break;
			}
		}
	  // Convert to digits all after non_digit_prefix until terminating zero, maybe empty string.
	  result.digits_value_combined += strtod(pin_field.c_str() + non_digit_prefix, nullptr);
		if (non_digit_prefix > 0) {
		  if (result.non_digit_text.empty()) {
			  result.non_digit_text = pin_field.substr(0, non_digit_prefix);
		  }
	  }
	}
	return result;
}

bool Pin::LessByNumberAndName::operator()(const std::shared_ptr<Pin> &a, const std::shared_ptr<Pin> &b) const {
	// This comparison operator MUST satisfy strict weak ordering definition; otherwise std::sort can crash!
	// for equal parts and numbers compare pin name, supporting strings like AA51. The order is like:
	// A0 A1..A9 A10 A11..A99 A100 A101..B0..Z0..AA0..AZ0..BA0..
	PinNameParseInfo a_parsed = pin_name_parse(a);
	PinNameParseInfo b_parsed = pin_name_parse(b);

	// compare non-digit prefixes lengths
	if (a_parsed.non_digit_text.size() != b_parsed.non_digit_text.size()) {
		return a_parsed.non_digit_text.size() < b_parsed.non_digit_text.size();
	}

	// compare non-digit prefixes of equal length if non-empty
	if (a_parsed.non_digit_text != b_parsed.non_digit_text) {
		return a_parsed.non_digit_text < b_parsed.non_digit_text;
	}
	return a_parsed.digits_value_combined < b_parsed.digits_value_combined;
}


std::vector<const std::string *> Component::searchableStringDetails() const {
	return {&mfgcode};
}

std::vector<const std::string *> Net::searchableStringDetails() const {
	std::vector<const std::string *> result = {};
	for (const auto &pin : pins) {
		result.push_back(&pin->name);
		if (pin->number != pin->name) {
			result.push_back(&pin->number);
		}
	}
	return result;
}
