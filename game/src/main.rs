#![warn(clippy::all)]

use winit::event_loop::EventLoop;
use winit::window::WindowBuilder;

fn main() {
    let events_loop = EventLoop::new();
    let window = WindowBuilder::new()
        .with_title("YEEEEEEEEEEEE")
        .build(&events_loop)
        .expect("Could not create a window!");
    loop {}
}
