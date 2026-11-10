# Semester Project Summary 

## Context & project description
For a C++ development course in my home university, I had to make a simple working game using C++ and SFML. 
I did make games with Unity before, and wanted to get back the feelings of how you make a game with Unity. 
So I started to program a kind of homemade Entity Component System game engine with enough generic built-in features to make any simple 2D games with.
(/!\ the architecture is not an ECS, but it feels like from the outside.)

It uses XML (instead of the graphical interface of Unity) to design scenes, premade gameObjects and animation trees.
The main goal is to program only components that we can attach to gameObject to give them specific behaviors.

## Patterns used so far

### Creational
* **Factory Method** (GameObject Factory)
* **Factory + self registration ??** (components)
  * a new Component class self register to the ComponentFactory with :
  ```cpp
     static inline bool s_registered = ComponentFactory::Register("Animator", [](const pugi::xml_node& node) -> std::unique_ptr<Component> {
        return std::make_unique<Animator>(node.attribute("src").as_string());
     });
    ```
  
### Structural
* **Composite** (Transform / GameObject)


## Pattern that may be used in the future:
### Creational
* **Abstract Factory**
  * maybe Scene GameObjects and Components can all be constructed by a big SceneFactory
  * This can also encapsulate the `pugi::xml` dependency that `Scene` has right now.
* **Prototype**
  * at the moment if you put 2 prefab line in the XML scene, the program will read the prefab's XML file twice to build twice the same thing or almost the same thing
  * file reading is **very heavy** in performance 

### Behavioural
* **Template Method** → onEnable(), onDisable(), Awake(), Start()
  * solves a need to clearly separate multiple wave of action (first building everything, then enabling everything, then starting everything, etc)  
* _Command for animation events ?_ (not sure)
  * it works with registered lambda on a frame

### Structural
* **Flyweight**
  * there is a need of that pattern basically everywhere, but in particular for textures
---


* Other idea may come later
* UI library (`TGUI`) is not encapsulated at all → maybe find something to fix that

## Git

Project's remote is here so far, it will be mirrored on the UNIZA Gitlab in the future.
https://github.com/AntoFruch/PatternFactory


## Questions
 * dependency injection ??
   * for self registration
   * to replace my static Managers