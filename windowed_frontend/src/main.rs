#[warn(clippy::all)]
use std::io::{stdin, stdout, Write};

use simple_logger::SimpleLogger;
use winit::event::{ElementState, Event, KeyboardInput, VirtualKeyCode, WindowEvent};
use winit::event_loop::{ControlFlow, EventLoop};
use winit::monitor::{MonitorHandle, VideoMode};
use winit::window::{Fullscreen, WindowBuilder};

fn main() {
    SimpleLogger::new().init().unwrap();
    let event_loop = EventLoop::new();

    let fullscreen = Fullscreen::Borderless(None);

    let mut is_maximized = true;
    let mut decorations = false;

    let window = WindowBuilder::new()
        .with_title("Hello world!")
        .with_fullscreen(Some(fullscreen.clone()))
        .build(&event_loop)
        .unwrap();

    event_loop.run(move |event, _, control_flow| {
        *control_flow = ControlFlow::Wait;

        match event {
            Event::WindowEvent { event, .. } => match event {
                WindowEvent::CloseRequested => *control_flow = ControlFlow::Exit,
                WindowEvent::KeyboardInput {
                    input:
                        KeyboardInput {
                            virtual_keycode: Some(virtual_code),
                            state,
                            ..
                        },
                    ..
                } => match (virtual_code, state) {
                    (VirtualKeyCode::Escape, _) => *control_flow = ControlFlow::Exit,
                    (VirtualKeyCode::F, ElementState::Pressed) => {
                        if window.fullscreen().is_some() {
                            window.set_fullscreen(None);
                        } else {
                            window.set_fullscreen(Some(fullscreen.clone()));
                        }
                    }
                    (VirtualKeyCode::W, ElementState::Pressed) => {
                        println!("W pressed");
                    }
                    (VirtualKeyCode::A, ElementState::Pressed) => {
                        println!("A pressed");
                    }
                    (VirtualKeyCode::S, ElementState::Pressed) => {
                        println!("S pressed");
                    }
                    (VirtualKeyCode::D, ElementState::Pressed) => {
                        println!("D pressed");
                    }
                    _ => (),
                },
                _ => (),
            },
            _ => {}
        }
        window.request_redraw();
    });
}
