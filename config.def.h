#ifdef _WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
enum {
	WIN_WIDTH  = 800,
	WIN_HEIGHT = 600
};

/* bar font:
 * (see fonts-conf(5) subsection "FONT NAMES" for valid values)
 */
static const char * const BAR_FONT = "monospace:size=8";

/* colors:
 * (see X(7) section "COLOR NAMES" for valid values)
 */
static const char * const WIN_BG_COLOR = "#555555";
static const char * const WIN_FS_COLOR = "#000000";
static const char * const SEL_COLOR    = "#EEEEEE";
static const char * const BAR_BG_COLOR = "#222222";
static const char * const BAR_FG_COLOR = "#EEEEEE";

#endif
#ifdef _IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
      1.0,    2.0,    3.0,    4.0,    5.0,    6.0,    7.0,    8.0,    9.0,
	   10.0,   20.0,   30.0,   40.0,   50.0,   60.0,   70.0,   80.0,   90.0,
	  100.0, 
	  200.0,  300.0,  400.0,  500.0,  600.0,  700.0,  800.0,  900.0, 1000.0,
	 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0,10000.0,
};

/* default slideshow delay (in sec, overwritten via -S option): */
enum { SLIDESHOW_DELAY = 5 };

/* gamma correction: the user-visible ranges [-GAMMA_RANGE, 0] and
 * (0, GAMMA_RANGE] are mapped to the ranges [0, 1], and (1, GAMMA_MAX].
 * */
static const double GAMMA_MAX   = 10.0;
static const int    GAMMA_RANGE = 32;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 5;

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding
 */
static const bool ALPHA_LAYER = false;

#endif
#ifdef _THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160 };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 1;

#endif
#ifdef _MAPPINGS_CONFIG

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ 0,            XK_q,             g_quit,               None },
	{ 0,            XK_Return,        g_switch_mode,        None },

	{ 0,            XK_e,             g_toggle_bar,         None },
	{ 0,            XK_v,             g_toggle_bar,         None },

	{ ControlMask,  XK_x,             g_prefix_external,    None },
	{ 0,            XK_g,             g_first,              None },
	{ 0,            XK_G,             g_n_or_last,          None },

	{ 0,            XK_r,             g_reload_image,       None },
	{ 0,            XK_R,             t_reload_all,         None },

	{ 0,            XK_n,             i_navigate,           +1 },
	{ 0,            XK_n,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_b,             i_navigate,           -1 },
	{ 0,            XK_b,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },


	//{ 0,            XK_D,             g_remove_image,       None },
	{ ControlMask,  XK_h,             g_scroll_screen,      DIR_LEFT },
	{ ControlMask,  XK_a,             g_scroll_screen,      DIR_LEFT },
	{ ControlMask,  XK_Left,          g_scroll_screen,      DIR_LEFT },

	{ ControlMask,  XK_j,             g_scroll_screen,      DIR_DOWN },
	{ ControlMask,  XK_s,             g_scroll_screen,      DIR_DOWN },
	{ ControlMask,  XK_Down,          g_scroll_screen,      DIR_DOWN },

	{ ControlMask,  XK_k,             g_scroll_screen,      DIR_UP },
	{ ControlMask,  XK_w,             g_scroll_screen,      DIR_UP },
	{ ControlMask,  XK_Up,            g_scroll_screen,      DIR_UP },

	{ ControlMask,  XK_l,             g_scroll_screen,      DIR_RIGHT },
	{ ControlMask,  XK_d,             g_scroll_screen,      DIR_RIGHT },
	{ ControlMask,  XK_Right,         g_scroll_screen,      DIR_RIGHT },

	{ 0,            XK_plus,          g_zoom,               +1 },
	{ 0,            XK_KP_Add,        g_zoom,               +1 },
	{ 0,            XK_minus,         g_zoom,               -1 },
	{ 0,            XK_KP_Subtract,   g_zoom,               -1 },
	{ 0,            XK_A,             g_zoom,               -1 },
	{ 0,            XK_D,             g_zoom,               +1 },

	{ 0,            XK_m,             g_toggle_image_mark,  None },
	{ 0,            XK_M,             g_reverse_marks,      None },
	{ ControlMask,  XK_m,             g_unmark_all,         None },
	{ 0,            XK_N,             g_navigate_marked,    +1 },
	{ 0,            XK_P,             g_navigate_marked,    -1 },
	{ 0,            XK_braceleft,     g_change_gamma,       -1 },
	{ 0,            XK_braceright,    g_change_gamma,       +1 },
	{ ControlMask,  XK_g,             g_change_gamma,        0 },

	{ 0,            XK_h,             t_move_sel,           DIR_LEFT },
	{ 0,            XK_a,             t_move_sel,           DIR_LEFT },
	{ 0,            XK_Left,          t_move_sel,           DIR_LEFT },

	{ 0,            XK_j,             t_move_sel,           DIR_DOWN },
	{ 0,            XK_s,             t_move_sel,           DIR_DOWN },
	{ 0,            XK_Down,          t_move_sel,           DIR_DOWN },

	{ 0,            XK_k,             t_move_sel,           DIR_UP },
	{ 0,            XK_w,             t_move_sel,           DIR_UP },
	{ 0,            XK_Up,            t_move_sel,           DIR_UP },

	{ 0,            XK_l,             t_move_sel,           DIR_RIGHT },
	{ 0,            XK_d,             t_move_sel,           DIR_RIGHT },
	{ 0,            XK_Right,         t_move_sel,           DIR_RIGHT },

	{ 0,            XK_bracketright,  i_navigate,           +10 },
	{ 0,            XK_bracketleft,   i_navigate,           -10 },
	{ ControlMask,  XK_6,             i_alternate,          None },
	{ ControlMask,  XK_n,             i_navigate_frame,     +1 },
	{ ControlMask,  XK_p,             i_navigate_frame,     -1 },
	{ ControlMask,  XK_space,         i_toggle_animation,   None },

	{ 0,            XK_h,             i_scroll,             DIR_LEFT },
	{ 0,            XK_a,             i_scroll,             DIR_LEFT },
	{ 0,            XK_Left,          i_scroll,             DIR_LEFT },

	{ 0,            XK_j,             i_scroll,             DIR_DOWN },
	{ 0,            XK_s,             i_scroll,             DIR_DOWN },
	{ 0,            XK_Down,          i_scroll,             DIR_DOWN },

	{ 0,            XK_k,             i_scroll,             DIR_UP },
	{ 0,            XK_w,             i_scroll,             DIR_UP },
	{ 0,            XK_Up,            i_scroll,             DIR_UP },

	{ 0,            XK_l,             i_scroll,             DIR_RIGHT },
	{ 0,            XK_d,             i_scroll,             DIR_RIGHT },
	{ 0,            XK_Right,         i_scroll,             DIR_RIGHT },

	{ 0,            XK_H,             i_scroll_to_edge,     DIR_LEFT },
	{ 0,            XK_J,             i_scroll_to_edge,     DIR_DOWN },
	{ 0,            XK_K,             i_scroll_to_edge,     DIR_UP },
	{ 0,            XK_L,             i_scroll_to_edge,     DIR_RIGHT },

	{ 0,            XK_equal,         i_set_zoom,           100 },
	{ 0,            XK_w,             i_fit_to_win,         SCALE_DOWN },
	{ 0,            XK_W,             i_fit_to_win,         SCALE_FIT },
	{ 0,            XK_c,             i_fit_to_win,         SCALE_WIDTH },
	{ 0,            XK_z,             i_fit_to_win,         SCALE_HEIGHT },

	{ 0,            XK_less,          i_rotate,             DEGREE_270 },
	{ 0,            XK_greater,       i_rotate,             DEGREE_90 },
	{ 0,            XK_question,      i_rotate,             DEGREE_180 },

	{ 0,            XK_bar,           i_flip,               FLIP_HORIZONTAL },
	{ 0,            XK_underscore,    i_flip,               FLIP_VERTICAL },

	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_A,             i_toggle_alpha,       None },
	{ 0,            XK_s,             i_slideshow,          None },
	
	{ 0,            XK_Home,          i_scroll_to_edge,     DIR_UP },
	{ 0,            XK_End,           i_scroll_to_edge,     DIR_DOWN },
	{ 0,            XK_Prior,         g_scroll_screen,      DIR_UP },
	{ 0,            XK_Next,          g_scroll_screen,      DIR_DOWN },

	{ 0,						XK_x,             g_hello_world,        None },
	{ ControlMask,	XK_D,             g_delete_file,        None },
/* JASON EDITS 
	{ false,  XK_o,             jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv o &" },
	{ false,  XK_f,             jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv + \"$SXIV_IMG\" &" },
	{ false,  XK_F,             jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv - \"$SXIV_IMG\" &" },
	{ true,   XK_f,             jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv +2 \"$SXIV_IMG\" &" },
	{ true,   XK_F,             jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv -2 \"$SXIV_IMG\" &" },
	{ false,  XK_F12,           jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv r \"$SXIV_IMG\" &" },
	{ false,  XK_F1,            jlsxiv,               (arg_t) "~/jkl/bin/t440s/jlsxiv r \"$SXIV_IMG\" &" },
	{ false,  XK_F6,            g_shell_cmd,         (arg_t) "mv \"$SXIV_IMG\" $(dirname $(dirname \"$SXIV_IMG\"))" },
*/

};

/* mouse button mappings for image mode: */
static const button_t buttons[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                i_cursor_navigate,    None },
	{ 0,            2,                i_drag,               None },
	{ 0,            3,                g_switch_mode,        None },
	{ 0,            4,                g_zoom,               +1 },
	{ 0,            5,                g_zoom,               -1 },
};

#endif
