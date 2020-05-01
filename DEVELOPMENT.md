# Development

---

- **4/21/2020** Managed to successfully compile CMake
    - Encountered and resolved error regarding CINDER_PATH
        - Somehow the CINDER_PATH variable in all the CMake files were changed
        - It took me a long time to troubleshoot because the error messages were correlated to other lines of code (not the variable declaration)
            - Due to my unfamiliarity with CMake, I didn't realize the error was with the variable declaration itself and not with the lines in the error messages
    - Tried SFML and Godot, but couldn't figure out a way to integrate either of them into the exisitng final project
        - Decided to try and switch to Box2D, will try to integrate it tomorrow
        
    

- **4/23/2020** Managed to successfully import Box2D
    - Encountered permissions error (error code 13)
        - Resolved by editing the executable in the configurations
    - Had to reinstall Cinder because CLion wasn't recognizing Box2D cloned from git
        - When I tried to include Box2D in CMake/the header in my code, CLion didn't recognize it
        - Not sure why exactly reinstalling Cinder worked, I just saw someone else do it on Piazza to address the same issue so I tried it out 


- **4/24/2020** Successfully added base objects from Box2D
    - Added and defined a vector object for gravity and used it to initiate a world object
        - Printed out one of the vector values to verify that everything worked
        
- **4/28/2020** Worked on figuring out how to visually display a Box2D World object in Cinder
    - The official Box2D tutorials and documentation online only talked about how to create things with the default Box2D library
        - Had to find a way to integrate it with Cinder
        - Added ConversionUtils to convert from the Box2D world to the Cinder display
        - Added GameWorld class to store all the parts of a specific scene/level in the game
            - Makes it easier to add more levels later on, allowing for more scalability
            
 - **4/29/2020**
    - Fleshed out ConversionUtils and GameWorld classes
        - Added various scaling helper functions to ConversionUtils to (hopefully) be able to scale the GameWorld properly
    - Changed how I planned on storing the body data in GameWorld class a few times
        - Initially it was going to be a vector of b2BodyDefs
        - Changed to a vector of b2Body* instead (since that's what the actualy fixtures are tied to)
        - Decided to create a GameBody class instead to store all my data
            - This way I can also keep track of the exact size, color, etc of all the blocks
            - Realized this would be necessary when I started to fill in code for the DrawWorld function in my_app
    - Added the GameBody class to store all information related to a given body, will flesh out later
            
        