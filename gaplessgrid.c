void
gaplessgrid(Monitor *m)
{
	unsigned int n = 0, i = 0, ch, cw, cn, rn, rows, cols;
	Client *c;

	wl_list_for_each(c, &clients, link)
		if (VISIBLEON(c, m) && !c->isfloating)
			n++;
	if (n == 0)
		return;

	/* grid dimensions */
	for (cols = 0; cols <= (n / 2); cols++)
		if ((cols * cols) >= n)
			break;

	if (n == 5) /* set layout against the general calculation: not 1:2:2, but 2:3 */
		cols = 2;

    /* widescreen is better if 3 columns */
    if (n >= 3 && n <= 6 && (m->w.width / m->w.height) > 1)
        cols = 3;

	rows = n / cols;
    
	/* window geometries */
	cw = cols ? m->w.width / cols : m->w.width;
	cn = 0; /* current column number */
	rn = 0; /* current row number */
	wl_list_for_each(c, &clients, link) {
		unsigned int cx, cy;
		if (!VISIBLEON(c, m) || c->isfloating || c->isfullscreen)
			continue;

		if ((i / rows + 1) > (cols - n % cols))
			rows = n / cols + 1;
		ch = rows ? m->w.height / rows : m->w.height;
		cx = m->w.x + cn * cw;
		cy = m->w.y + rn * ch;
		resize(c, (struct wlr_box) { cx, cy, cw, ch}, 0);
		rn++;
		if (rn >= rows) {
			rn = 0;
			cn++;
		}
		i++;
	}
}
