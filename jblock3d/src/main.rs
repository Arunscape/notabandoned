use raylib::prelude::*;

const WINDOW_WIDTH: i32 = 1280;
const WINDOW_HEIGHT: i32 = 720;

struct Cube {
    x: i32,
    y: i32,
    z: i32,
    tex_id: usize,
}


fn main() {
    let (mut rl, thread) = raylib::init()
        .size(WINDOW_WIDTH, WINDOW_HEIGHT)
        .title("Hello, world!")
        .build();

    let t_stone = rl
        .load_texture(&thread, "stone.png")
        .expect("could not load stone texture");

    let t_box = rl
        .load_texture(&thread, "box.png")
        .expect("could not load box texture");
    let texts = vec![t_stone, t_box];

    let mut camera = Camera3D::perspective(
        Vector3::new(0.0, 1.8, 0.0),
        Vector3::new(0.0, 0.0, 0.0),
        Vector3::new(0.0, 1.0, 0.0),
        45.0,
    );

    let cubes = vec![
        Cube{x: 0, y: 0, z: 0, tex_id: 0},
        Cube{x: 1, y: 0, z: 0, tex_id: 0},
        Cube{x: 2, y: 0, z: 0, tex_id: 0},
        Cube{x: 3, y: 0, z: 0, tex_id: 0},
        Cube{x: 4, y: 0, z: 0, tex_id: 0},
        Cube{x: 2, y: 1, z: 0, tex_id: 1},
    ];

    rl.set_camera_mode(&camera, CameraMode::CAMERA_FIRST_PERSON);
    rl.set_target_fps(60);

    while !rl.window_should_close() {
        rl.update_camera(&mut camera);

        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::BLACK);
        {
            let mut d2 = d.begin_mode3D(camera);

            for c in &cubes {
                d2.draw_cube_texture(&texts[c.tex_id], Vector3::new(c.x as f32, c.y as f32, c.z as f32), 1.0, 1.0, 1.0, Color::BLUE);
            }

        }
        d.draw_rectangle(10, 10, 220, 70, Color::SKYBLUE);
        d.draw_rectangle_lines(10, 10, 220, 70, Color::BLUE);
        d.draw_text(
            "First person camera default controls:",
            20,
            20,
            10,
            Color::BLACK,
        );
        d.draw_text("- Move with keys: W, A, S, D", 40, 40, 10, Color::DARKGRAY);
        d.draw_text("- Mouse move to look around", 40, 60, 10, Color::DARKGRAY);
    }
}
