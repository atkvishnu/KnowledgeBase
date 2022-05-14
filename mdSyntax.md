# Headings        
## Heading 2
### Heading 3
#### Heading 4
##### Heading 5
###### Heading 6	

Heading level 1					
===========
<h1>LOL</h1>

Heading Level 2							
-----------------
<h2>LOL</h2>

---

Paragraph : 
To create paragraphs, use a blank line to separate one or more lines of text.

Inline Code :
text `Inline Code` text	
At the command prompt, type <code>nano</code>.

Escaping Backticks :
``Use `code` in your Markdown file.``



~~Mistaken text.~~	

*Italics*	

**Bold**			__BOLD__dd

line break <br> line  <br>line

---

Tasks
- [x] a task list item
- [ ] list syntax required
- [ ] normal **formatting**
- [ ] incomplete
- [x] completed

---

Code Blocks

	means 
    4 space indention
    makes full-width
    standard code blocks

```js
var now = new Date();

var days = new Array('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');

var months = new Array('January','February','March','April','May','June','July','August','September','October','November','December');

var date = ((now.getDate()<10) ? "0" : "")+ now.getDate();

function fourdigits(number)	{
	return (number < 1000) ? number + 1900 : number;
								}
today =  days[now.getDay()] + ", " +
         months[now.getMonth()] + " " +
         date + ", " +
         (fourdigits(now.getYear())) ;

document.write(today);
```

```css
#sc_drag_area {
  height:100px;
  left:150px;
  position: absolute;
  top:100px;
  width:250px;
  z-index: 9999;
}
```

```c++
#include <iostream>
using namespace std;

int main()
{
	cout << "Hwllo, World! " << endl;
}
```
---

* List item one
* List item two
    * A nested item

---

1. Number list item one		
	1.1. A nested item
2. Number list item two
3. Number list item three

---

BlockQuotes

> BlockQuote
> 
> Second line BlockQuote

Nested BlockQuotes

> Dorothy followed her through many of the beautiful rooms in her castle.
>
>> The Witch clean.

Blockquotes with other elements

> #### The quarterly results look great!
>
> - Revenue was off the chart.
> - Profits were higher than ever.
>
>  *Everything* is going according to **plan**.






---

Links : 

Standard link =  http://ghost.org	
[Custom Text Link](http://ghost.org)

---

![Image](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fjustyy.com%2Fwp-content%2Fuploads%2F2016%2F01%2Fmarkdown-syntax-language.png&f=1&nofb=1)


Adding Titles :

My favorite search engine is [Duck Duck Go](https://duckduckgo.com "The best search engine for privacy").


URLs and Email Addresses :

<https://www.markdownguide.org>
<fake@example.com>


Formatting Links :


I love supporting the **[EFF](https://eff.org)**.
This is the *[Markdown Guide](https://www.markdownguide.org)*.
See the section on [`code`](#code).



---

Table

| Left-Aligned  | Center Aligned  | Right Aligned |
| :------------ |:---------------:| -----:|
| col 3 is      | some wordy text | $1600 |
| col 2 is      | centered        |   $12 |
| zebra stripes | are neat        |    $1 |





[[tags]]

==highlight==



Starting unordered list items with numbers

- 1968\. A great year!  
- I think 1969 was second best.




Horizontal Rules :

These 3 give same output: 

***

---
 
________________




