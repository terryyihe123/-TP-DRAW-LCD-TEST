
typedef struct _tp_pos
{
    int x;
    int y;
} tp_pos;

typedef struct _area_info
{
    tp_pos left_top;
    tp_pos right_bottom;
    char drawed;
} area_info;

static tp_pos cur_pos;
static tp_pos last_pos;

#define AREA_ROW  11
#define AREA_COL  5
area_info rect_r1 [AREA_ROW];
area_info rect_r2 [AREA_ROW];
area_info rect_c1 [AREA_COL];
area_info rect_c2 [AREA_COL];

int width = 0;
int height = 0;
int tp_width = 0;
int tp_height = 0;
int rect_w = 0;
int rect_h = 0;
char tp_flag = 0;

static int rect_cnt;

void area_rectangle_check(int x, int y);


void draw_rectangle(area_info rect)
{
    if(rect.drawed == 0)
        ui_set_color(CL_RED);
    else
        ui_set_color(CL_GREEN);

    ui_draw_line_mid(rect.left_top.x, rect.left_top.y, rect.right_bottom.x, rect.left_top.y);
    ui_draw_line_mid(rect.left_top.x, rect.left_top.y, rect.left_top.x, rect.right_bottom.y);
    ui_draw_line_mid(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.x, rect.left_top.y);
    ui_draw_line_mid(rect.right_bottom.x, rect.right_bottom.y, rect.left_top.x, rect.right_bottom.y);
}

void area_rectangle_init(void)
{
    int i = 0;
    int start_width = (width % AREA_COL) / 2;
    int start_height = (height % AREA_ROW) / 2;

    rect_cnt = 0;

    LOGD("width=%d, height=%d", width, height);
    LOGD("rect_w=%d, rect_h=%d", rect_w, rect_h);

    for(i = 0; i < AREA_ROW; i++)
    {
        rect_r1[i].left_top.x = 0;
        rect_r2[i].left_top.x = rect_w * (AREA_COL - 1) + start_width;
        if(i == 0)
        {
            rect_r1[i].left_top.y = 0;
            rect_r2[i].left_top.y = 0;
        }
        else
        {
            rect_r1[i].left_top.y = i * rect_h + start_height;
            rect_r2[i].left_top.y = i * rect_h + start_height;
        }

        rect_r1[i].right_bottom.x = rect_w + start_width;
        rect_r2[i].right_bottom.x = width - 1;
        if( i == AREA_ROW - 1)
        {
            rect_r1[i].right_bottom.y = height - 1;
            rect_r2[i].right_bottom.y = height - 1;
        }
        else
        {
            rect_r1[i].right_bottom.y = (i + 1) * rect_h + start_height;
            rect_r2[i].right_bottom.y = (i + 1) * rect_h + start_height;
        }

        rect_r1[i].drawed = 0;
        rect_r2[i].drawed = 0;
        draw_rectangle(rect_r1[i]);
        draw_rectangle(rect_r2[i]);
    }

    for(i = 0; i < AREA_COL; i++)
    {
        if( i == 0 )
        {
            rect_c1[i].left_top.x = 0;
            rect_c2[i].left_top.x = 0;
        }
        else
        {
            rect_c1[i].left_top.x = i * rect_w + start_width;
            rect_c2[i].left_top.x = i * rect_w + start_width;
        }
        rect_c1[i].left_top.y = 0;
        rect_c2[i].left_top.y = (rect_h * (AREA_ROW - 1)) + start_height;

        if( i == AREA_COL - 1 )
        {
            rect_c1[i].right_bottom.x = width - 1;
            rect_c2[i].right_bottom.x = width - 1;
        }
        else
        {
            rect_c1[i].right_bottom.x = (i + 1) * rect_w + start_width;
            rect_c2[i].right_bottom.x = (i + 1) * rect_w + start_width;
        }

        rect_c1[i].right_bottom.y = rect_h + start_height;
        rect_c2[i].right_bottom.y = height - 1;

        rect_c1[i].drawed = 0;
        rect_c2[i].drawed = 0;
        draw_rectangle(rect_c1[i]);
        draw_rectangle(rect_c2[i]);
    }

    gr_flip();
}
