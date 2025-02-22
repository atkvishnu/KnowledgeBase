# [Use of symbols '@', '&', '=' and '>' in custom directive's scope binding: AngularJS](https://stackoverflow.com/questions/37818740/use-of-symbols-and-in-custom-directives-scope-binding-angula)

`<` one-way binding
`=` two-way binding
`&` function binding
`@` pass only strings

---

`>` is not in the documentation.

`<` is for one-way binding.

`@` binding is for passing strings. These strings support `{{}}` expressions for interpolated values.

`=` binding is for two-way model binding. The model in parent scope is linked to the model in the directive's isolated scope.

`&` binding is for passing a method into your directive's scope so that it can be called within your directive.

When we are setting scope: true in directive, Angular js will create a new scope for that directive. That means any changes made to the directive scope will not reflect back in parent controller.

---

In an AngularJS directive the scope allows you to access the data in the attributes of the element to which the directive is applied.

This is illustrated best with an example:

```xml
<div my-customer name="Customer XYZ"></div>
```

and the directive definition:

```javascript
angular.module('myModule', [])
.directive('myCustomer', function() {
  return {
    restrict: 'E',
    scope: {
      customerName: '@name'
    },
    controllerAs: 'vm',
    bindToController: true,
    controller: ['$http', function($http) {
      var vm = this;

      vm.doStuff = function(pane) {
        console.log(vm.customerName);
      };
    }],
    link: function(scope, element, attrs) {
      console.log(scope.customerName);
    }
  };
});
```

When the `scope` property is used the directive is in the so called "isolated scope" mode, meaning it can not directly access the scope of the parent controller.

In very simple terms, the meaning of the binding symbols is:

`someObject: '='` (two-way data binding)

`someString: '@'` (passed directly or through interpolation with double curly braces notation `{{}}`)

`someExpression: '&'` (e.g. `hideDialog()`)

This information is present in the [AngularJS directive documentation page](https://docs.angularjs.org/guide/directive), although somewhat spread throughout the page.

The symbol `>` is not part of the syntax.

However, `<` does exist as part of the [AngularJS component bindings](https://docs.angularjs.org/guide/component) and means one way binding.