#!/usr/bin/env python3
#renders pinout csv copied from OpenBoardView to pdf
import sys
import csv
from reportlab.pdfgen import canvas
from reportlab.lib.units import mm
def write_on_canvas(in_name, c, radius, scale):
	c.scale(scale, scale)
	pinout = csv.reader(open(in_name).readlines()[1:], delimiter=" ")
	for pin in pinout:
		name = pin[0] + "_" + pin[1]
		pos = (float(pin[3]), float(pin[4]))
		c.circle(pos[0], pos[1], radius, stroke=0, fill=1)

#internal units are in 72DPI.

c = canvas.Canvas(sys.argv[1]+".pdf")
c.setPageCompression(0);
c.setFillColorRGB(0,0,0)
radius = 0.0065
scale = 49.4*mm
shift = scale * 1.03
fix_x = shift * 1.075
fix_y = 15*mm
for j, r in enumerate((0., 0.0012)):
	scales = (-0.3, -0.15, 0., 0.15, 0.3)
	if j%2 == 1:
		scales = reversed(scales)
	for i, s in enumerate(scales):
		c.saveState()
		y_shift = fix_y + shift * i * 1.03
		c.translate(fix_x+ 2 *shift * j, y_shift)
		write_on_canvas(sys.argv[1], c, radius + r, scale + s *mm)
		c.restoreState()
		c.saveState()
		c.translate(fix_x+ 2 *shift * j - shift * 0.03, y_shift)
		c.scale(-1, 1)
		write_on_canvas(sys.argv[1], c, radius + r, scale + s *mm)
		c.restoreState()
c.showPage()
c.save()
