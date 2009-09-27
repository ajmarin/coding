#include <locale.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <string.h>

/* defines */
#define USAGE printf("usage: %s [-h] [wmname]\n", argv[0])

/* enums */
enum { NET_SUPPORTED, NET_SUPPORTING_WM_CHECK, NET_WM_NAME, UTF8_STRING, ATOMS_NUM };

/* prototypes */
int getwmname(char **dest);
void loadatoms(void);
int main(int argc, char *argv[]);
void setwmname(const char *wmname);

/* variables */
Atom atoms[ATOMS_NUM];
Display *dpy;
Window root;
int screen;

/* functions */
int getwmname(char **dest) {
	int real_format;
	Atom real_type;
	unsigned long items_read, items_left;
	char *data;

	if(XGetWindowProperty(dpy, root, atoms[NET_SUPPORTING_WM_CHECK], 0, 1, 0, XA_WINDOW, &real_type, &real_format,
				&items_read, &items_left, (unsigned char **)&data) == Success && items_read) {
		Window check_window = *((unsigned int*)data);
		XFree(data);

		if(XGetWindowProperty(dpy, check_window, atoms[NET_WM_NAME], 0, 6, 0, atoms[UTF8_STRING], &real_type, &real_format,
					&items_read, &items_left, (unsigned char **)&data) == Success && items_read) {
			*dest = data;
			return items_read;
		}
	}

	return 0;
}

void loadatoms(void) {
	atoms[NET_SUPPORTING_WM_CHECK] = XInternAtom(dpy, "_NET_SUPPORTING_WM_CHECK", False);
	atoms[NET_WM_NAME] = XInternAtom(dpy, "_NET_WM_NAME", False);
	atoms[UTF8_STRING] = XInternAtom(dpy, "UTF8_STRING", False);
}

int main(int argc, char *argv[]) {
	if(!(dpy = XOpenDisplay(0))) {
		fprintf(stderr, "%s: cannot open display\n", argv[0]);
		return 1;
	}

	screen = DefaultScreen(dpy);
	root = RootWindow(dpy, screen);

	loadatoms();

	if(argc == 1) {
		char *wmname;
		if(getwmname(&wmname))
			printf("Current WM name: %s\n", wmname);
		else
			printf("No WM name set.\n");
	} else if(argc == 2) {
		if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
			USAGE;
		else
			setwmname(argv[1]);
	} else
		USAGE;

	XCloseDisplay(dpy);

	return 0;
}

void setwmname(const char *wmname) {
	XChangeProperty(dpy, root, atoms[NET_SUPPORTING_WM_CHECK], XA_WINDOW, 32, PropModeReplace, (unsigned char *)&root, 1);
	XChangeProperty(dpy, root, atoms[NET_WM_NAME], atoms[UTF8_STRING], 8, PropModeReplace, (unsigned char *)wmname, strlen(wmname));
	XSync(dpy, False);
}

