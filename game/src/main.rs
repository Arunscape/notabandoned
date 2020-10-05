#![warn(clippy::all)]

use winit::event_loop::EventLoop;
use winit::monitor::MonitorHandle;
use winit::window::{Fullscreen, Window, WindowBuilder};

#[derive(Debug)]
pub struct WinitState {
    pub events_loop: EventLoop<()>,
    pub window: Window,
}

impl WinitState {
    /// It's possible for the window creation to fail. This is unlikely.
    pub fn new<T: Into<String>>(title: T) -> Result<Self, CreationError> {
        let events_loop = EventsLoop::new();
        let output = WindowBuilder::new()
            .with_fullscreen(Some(Fullscreen::Borderless(None)))
            .build(&events_loop);
        output.map(|window| Self {
            events_loop,
            window,
        })
    }
}

impl Default for WinitState {
    fn default() -> Self {
        Self::new("Chungus").expect("Could not create a window!")
    }
}

fn main() {
    let mut winit_state = WinitState::default();

    let events_loop = EventLoop::new();
    let window = WindowBuilder::new()
        .with_title("YEEEEEEEEEEEE")
        .build(&events_loop)
        .expect("Could not create a window!");
    loop {}
}
