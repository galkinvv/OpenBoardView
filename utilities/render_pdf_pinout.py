#!/usr/bin/env python3
#renders pinout csv copied from OpenBoardView to pdf
import sys
import csv
from reportlab.pdfgen import canvas
from reportlab.lib.units import mm
input_coord_scale = 1404/1944 # linear size relative to ga102 (~49.4mm between side ball centers)
ball_step_scale = 0.7/0.8 # distance between pins relative to ga102 (0.8mm)
def write_on_canvas(in_name, c, radius, scale):
	c.scale(scale, scale)
	pinout = csv.reader(open(in_name).readlines()[1:], delimiter=" ")
	c.circle(-0.015, 1.015, radius*2, stroke=0, fill=1)
	for pin in pinout:
		name = pin[0] + "_" + pin[1]
		pos = (float(pin[3]) * input_coord_scale, float(pin[4]) * input_coord_scale + (1. - input_coord_scale))
		c.circle(pos[0], pos[1], radius * ball_step_scale, stroke=0, fill=1)

#internal units are in 72DPI.

c = canvas.Canvas(sys.argv[1]+".pdf")
c.setPageCompression(0);
c.setFillColorRGB(0,0,0)
radius = 0.0065
scale = 49.4*mm
shift = scale * 1.13
fix_x = shift * 1
fix_y = 22*mm
for j, r in enumerate((0., 0.0003, 0.0006, 0.0009, 0.0012)):
	scales = (0.1, 0.13, 0.15)
	for i, s in enumerate(scales):
		y_shift = fix_y + shift * i
		c.saveState()
		c.translate(y_shift, fix_x+ shift * j*1.01)
		c.drawString(0,-scale*1.09,f"scale={s},radius={r}")
		c.scale(1, -1)
		write_on_canvas(sys.argv[1], c, radius + r, scale + s *mm)
		c.restoreState()
c.showPage()
c.save()
