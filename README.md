### Millie Game Engine
- Millie is an engine that is optimized for agile development in game jams and hackathons.
- Millie includes a low level rendering framework.
- Allows for the boot of the program, allocation memory, and communication with the OS.

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
