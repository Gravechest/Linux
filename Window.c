#include <X11/Xlib.h>
 int main(void) {
   Display *d;
   Window w;
   XEvent e;
   int s;
   d = XOpenDisplay(NULL);
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 100, 100, 1,
                           BlackPixel(d, s), WhitePixel(d, s));
   XSelectInput(d, w, ExposureMask | KeyPressMask);
   XMapWindow(d, w);
   for(;;) {
      XNextEvent(d, &e);
   }
   XCloseDisplay(d);
}
