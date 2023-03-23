### Millie Game Engine
- Millie is a 2D engine that is optimized for agile development in game jams and hackathons.
- Millie includes a low level rendering framework with SDL2. 
- Allows for the boot of the program, allocation memory, and communication with the OS.


**Input Handling**
- Get input from keyboard 
  - Be able to set custom keybinds


 **Rendering**
- Meshes 
- Shaders
- Batching


**Animation**
- Finite State Automata 
- Sprite based animation

**Physics**
- Static and Dynamic Physics 
- Collision Detection
- Collision Resolution

**User Interface**
- Window Management
  - Open initial menu window
    - move from one window to another
- Fully Functional GUI and level editor
  - Menu movement
    - button click
    - arrow key movement
      

**Camera**



**Basic Game Loop**
        
    while(isRunning)
    {
        Input->readInput();
        isRunning = GameLogic->doLogic();
        Camera->update();
        World->update();
        GUI->update();
        AI->update();
        Audio->play();
        Render->draw();
}
**Controls - State Machine**

    // TODO: add code for the state machine


**MakeFile** 

    mingw32-make -f MakeFile
    start main.exe