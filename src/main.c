#include <title.h>
#include <alt_title.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>



struct window {
    WINDOW* w;
    char* name;
    int x;
    int y;
    int width;
    int height;
};
struct window game_windows[ ] = { 
{ NULL, "GAME" , 0, 0, 150, 120 },
{},
};

void create_window(struct window* w) {
    w->w = newwin(w->height, w->width, w->y, w->x);
    wrefresh(w->w);
}

void create_windows(void) {
    for (struct window* w = game_windows; w->name; w++)
        create_window(w);
}

void init_ncurses(void) {
    setlocale(LC_ALL, "");
    initscr();
}

// Deconstructor for our window types.
void clean_win (struct window* w) {
    if (!w) { return; }
    if (w->w) { delwin(w->w); }
    return;
}

void refresh_windows (void) {
    for (struct window* w = game_windows; w->w != NULL; w++) {
        if (w->w) {
            //
            wrefresh(w->w);
        }
    }
}



int main(void) {
    init_ncurses();
    create_windows();
    wprintw(game_windows[0].w, "%s", title);
    refresh();
    refresh_windows();  /* Print it on to the real screen */
    getch();    /* Wait for user input */
    endwin();
    return EXIT_SUCCESS;
}
