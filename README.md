### Millie Game Engine
- Millie is a 2D engine that is optimized for agile development in game jams and hackathons.
- Millie includes a low level rendering framework with SDL2. 
- Allows for the boot of the program, allocation memory, and communication with the OS.

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
- Fully Functional GUI and level editor

**Basic Game Loop**
    
    LoadStuff();
    while(isRunning)
    {
        ProcessInput();
        UpdateGame();
        RenderGame(); // audio, graphics, etc.
    }
    UnloadStuff();

**Controls - State Machine**

    // TODO: add code for the state machine