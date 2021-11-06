
int test_lcd_start_common(void)
{
    int ret = 0;
    int row = 2;
    int key = 0;

    ui_fill_locked();
    //ui_fill_screen(255, 255, 255);
    //gr_flip();
    //usleep(500*1000);

    ui_fill_screen(128, 128, 128);
    gr_flip();
    usleep(3000*1000);

    ui_fill_screen(255, 255, 255);
    gr_flip();
    usleep(500*1000);

    key = ui_wait_key();
	
    ui_fill_locked();
    ui_show_title(MENU_TEST_LCD);
    gr_color(255, 255, 255, 255);
    row=ui_show_text(row, 0, TEXT_FINISH);
    ui_set_color(CL_GREEN);
    row=ui_show_text(row, 0, LCD_TEST_TIPS);
    gr_flip();

    usleep(10*1000);
    //ret = ui_handle_button(TEXT_PASS,NULL,TEXT_FAIL);

    //save_result(CASE_TEST_LCD,ret);
    usleep(500*1000);

    return ret;
}