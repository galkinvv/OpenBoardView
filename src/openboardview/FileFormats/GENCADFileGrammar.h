#ifndef GENCADFILEGRAMMAR_H
#define GENCADFILEGRAMMAR_H

/**
 *********************************************************************************
 *********************************************************************************
  WARNING THIS IS AN AUTOGENERATED FILE!!!
  Do not modify this file, but edit the:
  GENCADFileBnf.h file
  and then run:
  ./generate_grammar_header.sh GENCADFileBnf.h GENCADFileGrammar.h
 *********************************************************************************
 *********************************************************************************
 **/

#include "mpc/mpc.h"


#define X_MACRO_PARSE_VARS\
  X(s, "s")\
  X(n, "n")\
  X(sign, "sign")\
  X(number, "number")\
  X(p_integer, "p_integer")\
  X(string, "string")\
  X(nonquoted_string, "nonquoted_string")\
  X(string_to_end, "string_to_end")\
  X(arc_start, "arc_start")\
  X(arc_end, "arc_end")\
  X(arc_center, "arc_center")\
  X(arc_p1, "arc_p1")\
  X(arc_p2, "arc_p2")\
  X(arc_ref, "arc_ref")\
  X(artwork_name, "artwork_name")\
  X(attribute_category, "attribute_category")\
  X(attribute_name, "attribute_name")\
  X(attribute_data, "attribute_data")\
  X(radius, "radius")\
  X(circle_ref, "circle_ref")\
  X(component_name, "component_name")\
  X(dimension, "dimension")\
  X(drill_size, "drill_size")\
  X(fid_name, "fid_name")\
  X(filename, "filename")\
  X(filled_ref, "filled_ref")\
  X(flip, "flip")\
  X(height, "height")\
  X(width, "width")\
  X(layer_index, "layer_index")\
  X(layer, "layer")\
  X(line_start, "line_start")\
  X(line_end, "line_end")\
  X(line_ref, "line_ref")\
  X(mirror, "mirror")\
  X(pad_name, "pad_name")\
  X(pad_type, "pad_type")\
  X(part_name, "part_name")\
  X(pin_name, "pin_name")\
  X(probe, "probe")\
  X(rectangle_ref, "rectangle_ref")\
  X(rot, "rot")\
  X(shape_name, "shape_name")\
  X(sig_name, "sig_name")\
  X(tan, "tan")\
  X(testpad_name, "testpad_name")\
  X(text_size, "text_size")\
  X(text_text, "text_text")\
  X(text_par, "text_par")\
  X(tp_name, "tp_name")\
  X(track_name, "track_name")\
  X(track_width, "track_width")\
  X(via_name, "via_name")\
  X(x, "x")\
  X(y, "y")\
  X(x_y_ref, "x_y_ref")\
  X(header, "header")\
  X(major, "major")\
  X(minor, "minor")\
  X(gencad_version, "gencad_version")\
  X(user, "user")\
  X(drawing, "drawing")\
  X(revision, "revision")\
  X(unit, "unit")\
  X(units, "units")\
  X(origin, "origin")\
  X(intertrack, "intertrack")\
  X(attribute, "attribute")\
  X(name, "name")\
  X(thickness, "thickness")\
  X(line, "line")\
  X(arc, "arc")\
  X(circle, "circle")\
  X(rectangle, "rectangle")\
  X(cutout, "cutout")\
  X(mask, "mask")\
  X(artwork, "artwork")\
  X(board, "board")\
  X(pad, "pad")\
  X(pads, "pads")\
  X(padstacks_pad, "padstacks_pad")\
  X(padstack, "padstack")\
  X(padstacks, "padstacks")\
  X(layer_name, "layer_name")\
  X(named_layer, "named_layer")\
  X(filled, "filled")\
  X(text, "text")\
  X(artworks_artwork, "artworks_artwork")\
  X(artworks, "artworks")\
  X(fiducial, "fiducial")\
  X(insert, "insert")\
  X(height_, "height_")\
  X(shape_artwork, "shape_artwork")\
  X(fid, "fid")\
  X(shape_pin_name, "shape_pin_name")\
  X(shapes_pin, "shapes_pin")\
  X(shape, "shape")\
  X(shapes, "shapes")\
  X(device_name, "device_name")\
  X(device_, "device_")\
  X(place, "place")\
  X(rotation, "rotation")\
  X(shape_, "shape_")\
  X(artwork_, "artwork_")\
  X(sheet, "sheet")\
  X(component, "component")\
  X(components, "components")\
  X(part, "part")\
  X(type, "type")\
  X(style, "style")\
  X(package, "package")\
  X(pindesc, "pindesc")\
  X(pinfunct, "pinfunct")\
  X(pincount, "pincount")\
  X(tol, "tol")\
  X(ptol, "ptol")\
  X(ntol, "ntol")\
  X(volts, "volts")\
  X(desc, "desc")\
  X(value, "value")\
  X(partnumber, "partnumber")\
  X(device, "device")\
  X(devices, "devices")\
  X(node, "node")\
  X(nailloc, "nailloc")\
  X(signal, "signal")\
  X(signals, "signals")\
  X(track, "track")\
  X(tracks, "tracks")\
  X(define, "define")\
  X(layerset, "layerset")\
  X(layer_, "layer_")\
  X(layers, "layers")\
  X(track_, "track_")\
  X(route, "route")\
  X(nailloc_, "nailloc_")\
  X(via, "via")\
  X(testpad, "testpad")\
  X(plane, "plane")\
  X(routes, "routes")\
  X(hole, "hole")\
  X(fhole, "fhole")\
  X(mechanical, "mechanical")\
  X(mech, "mech")\
  X(testpin, "testpin")\
  X(testpins, "testpins")\
  X(powerpin, "powerpin")\
  X(powerpins, "powerpins")\
  X(pseudo_signal, "pseudo_signal")\
  X(pseudo_device, "pseudo_device")\
  X(pseudo_part, "pseudo_part")\
  X(pseudo_shape, "pseudo_shape")\
  X(pseudo_component, "pseudo_component")\
  X(pseudo_testpad, "pseudo_testpad")\
  X(pseudo_padstack, "pseudo_padstack")\
  X(pseudo_pin, "pseudo_pin")\
  X(pseudo_testpin, "pseudo_testpin")\
  X(pseudo_powerpin, "pseudo_powerpin")\
  X(pseudo_via, "pseudo_via")\
  X(pseudos, "pseudos")\
  X(sig_change, "sig_change")\
  X(dev_change, "dev_change")\
  X(change, "change")\
  X(changes, "changes")\
  X(gencad_file, "gencad_file")\
 /*empty string to end last continuation*/
#endif
