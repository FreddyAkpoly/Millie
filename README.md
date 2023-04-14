### Millie Game Engine
- Millie is a game engine that aims to reduce the computing power needed for mid to large cap applications
- Millie includes a low level rendering framework with SDL2. 


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


**Snapshots**

![Alt text](MillieEngineSnapShot.png?raw=true "Optional Title")