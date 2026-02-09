#pragma once

#include "BRDFileBase.h"

class CSTFile : public BRDFileBase {
  public:
	CSTFile(std::vector<char> &buf);

  private:
	void gen_outline();
	std::vector<char *> nets;
};
