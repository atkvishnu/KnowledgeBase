# Model View Controller (MVC)
- More on [MVC](https://developer.mozilla.org/en-US/docs/Glossary/MVC)

* We want to follow a certain pattern for structuring our code and with that, we don't really just mean how we split it over files or how we write the code but how we logically separate our code and the different functions it fulfills or the different things it does.

* MVC is a way of structuring our code. It is a way of separating the different parts of our code.

* MVC is all about separation of concerns. It's about making sure that different parts of your code do different things and we clearly know which part is responsible for what. MVC stands for model view controller. We work with models, views and controllers.

- MODELS: Represent the data in the code. Work with your data (ex, save, fetch, etc.)
* Responsible for representing your code.
* Responsible for managing your data (saving, fetching, ....)
* Doesn't matter if you manage data in memory, files, databases.
- Contain data-related logic.
- Models are basically objects or is a part of your code that is responsible for representing your data in your code and allowing you to work with your data, so things like saving data, fetching data to or from a file or even if it's just in memory as we're currently doing it, this should be handled by models.

- VIEWS: What the user sees. Decoupled from the application code.
* What the user sees
* Shouldn't contain too much logic!
- The views are responsible for what the user sees in the end, they are responsible for rendering the right content in our html documents and sending that back to the user, so they are decoupled from your application code and are just having some light or minor integrations regarding the data we inject into our templating engine to generate these views. 

- CONTROLLERS: Connecting the models and the views. Contains the in-between logic. 
* Connects Model and View
* Should only make sure that the two can communicate (in both directions).
- The controllers are now the connection point between the models and your views because since the views shouldn't care about the application logic and the models do care about how to save and fetch data and so on, the controllers are the thing working with the models, saving that data or triggering that save process and so on and also the part where they then pass that data that was fetched to your views. So the controller is the middleman, it contains the in-between logic.

- ROUTES: 
- Routes are basically the things which define upon which path for which http method which controller code should execute, the controller is then the thing defining with which model to work and which view to render.

- This is the pattern in which express application relies on this middleware concept, the controllers are also kind of split up across middleware functions or some of the logic might be separated and moved into another middleware function but we'll see all of that and we'll get there step by step.

