# Dynamic Content and Templates 
# Rendering more than static HTML

DB stores data-> served by server-> browser 

* Managing Data (without a Database - first)
* Rendering Dynamic Content in our views.
* Templating Engines - render HTML from a template.

# TEMPLATING ENGINE

`Templating Engines` - render HTML from a template. We can use a templating engine to render HTML from a template.
- `Templating engines` are basically `HTMLish template` with some `Placeholders`.
- We have our dummy array from our `Node/Express Content` which will replace the `Placeholders` in the templating engine. 
- Replaces `Placeholders`/ `Snippets` with HTML Content.

Overview:
*   HTMLish Template(Pug/ Handlebars/ EJS/ etc.)
                ⬇️
*   Node/ Express Content + Templating Engine
                ⬇️
*   Replace Placeholders/Snippets with HTML Content.
                ⬇️
*           Outputs HTML File (generated on the fly)


# Available Templating Engines
- Pug(Jade)
- Handlebars
- EJS

* All 3 have different syntax. 

> We can use these templating engines and enject our data into the template and generate HTML.


---

# ***EJS syntax***
* [EJS Docs](http://ejs.co/#docs)
* `npm install --save ejs`

app.set('view engine', 'ejs');
app.set('views', 'views');

* supported out of the box by express
* EJS doesn't support layouts, but we can use `<%- include('./....') %>` for HTML code!
* inside `<%  %>` normal Javascript code can be written.

- uses `<%- include('./....') %>` for HTML code using include.
- uses `<%= %>` for raw text.
- uses `<% %>` for code.
- uses `<%# %>` for comments.
- Uses normal HTML tags and plain JS (if-else statements) in our templates.

```html
<p><%= name %</p>
```


---

# [Pug syntax](https://pugjs.org/language/attributes.html)
* [Pug Docs](https://pugjs.org/api/getting-started.html)
* `npm install --save pug`
* supported out of the box by express
- uses `=` for data.
- uses `#` for comments.
- Uses minimal HTML and custom template language.

- Layout can also be created! Layout is a skeleton which can be reused in multiple pages.
- We can `extend` our layout from another pug views.
- **We can use `block` to create reusable snippets.**
- We can define some placeholders/ Hooks in our layout where other views can enter their content.

```pug
p #{name}
```

---

# Handlebars syntax
* [Handlebars Docs](https://handlebarsjs.com/)
* `npm install --save express-handlebars@3.0`

* All the logic needs to be in the JS files!

- Uses `{{}}` for data.
- Uses `{{!}}` for comments.
- Uses normal HTML and custom template language.
- Uses `{{#if}}` and `{{/if}}` for conditional statements.
- features are less than Pug/ EJS!

```handlebars
<p>{{name}}</p>
```

* Not supported out of the box. We have to import it first!

```js
const expressHbs = require('express-handlebars');

app.engine('handlebars', expressHbs.engine({
    layoutDir: 'views/layouts/',
    defaultLayout: 'main',
    extname: 'handlebars'
}));

app.set('view engine', 'handlebars');
app.set('views', 'views');
```

* dynamic content syntax
```handlebars
{{ <variable from JS file> }}
```

* if-else syntax
```handlebars
{{#if isLoggedIn}}
    <p>Welcome, {{name}}</p>
{{else}}
    <p>Please sign in</p>
{{/if}}
```

* layout

```handlebars
{{{ body }}}
```
* after setting this, we only need to include the body content in out .handlebars file.

---










