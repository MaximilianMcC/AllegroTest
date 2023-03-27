#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main()
{

    bool running = true;
    int x = 0, y = 0;

    al_init();

    ALLEGRO_DISPLAY* display = al_create_display(800, 800);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
    ALLEGRO_BITMAP* bitmap = NULL;

    al_install_keyboard();
    al_install_mouse();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_init_image_addon();

    bitmap = al_load_bitmap("./src/testimage.png");
    assert(bitmap != NULL);

    al_start_timer(timer);

    while (running)
    {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

            running = false;

        }

        if (event.type == ALLEGRO_EVENT_KEY_UP)
        {

            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {

                x -= 5;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {

                x += 5;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_UP)
            {

                y -= 5;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {

                y += 5;

            }

        }

        if (event.type == ALLEGRO_EVENT_TIMER)
        {

            al_clear_to_color(al_map_rgb(0, 0, 255));
            al_draw_pixel(10, 10, al_map_rgb(255, 255, 255));
            al_draw_bitmap(bitmap, x, y, 0);

            al_flip_display();

        }

    }
    
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_timer(timer);
    al_destroy_bitmap(bitmap);

    return 0;

}