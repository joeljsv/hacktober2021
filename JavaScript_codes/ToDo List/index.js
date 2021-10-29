//array to hold the todo list items
let todoItems = [];

//function to render the todo list items
function renderTodo(todo) {
    //to persist application state to the browser's localstorage
    localStorage.setItem('todoItems', JSON.stringify(todoItems));

    //select the first element with a class of 'js-todo-list'
    const list = document.querySelector('.js-todo-list');
    //select the current todo item in the DOM
    const item = document.querySelector(`[data-key='${todo.id}']`);

    //delete conditions check
    if(todo.deleted) {
        //remove the item from DOM if deleted is true
        item.remove();

        //when 'todoItems' is empty, clear all whitespace from the list container
        if(todoItems.length === 0){
            list.innerHTML = '';
        }
        return
    }

    //use the ternary operator to check if 'todo.checked' is true 
    //if so, assign 'done' to 'isChecked'. Otherwise, assign empty string
    const isChecked = todo.checked ? 'done' : '';

    //create a li element and assign to the 'node'
    const node = document.createElement("li");

    //set the class attribute
    node.setAttribute('class', `todo-item ${isChecked}`);

    //set the data-key attribute to the id of the todo
    node.setAttribute('data-key', todo.id);

    //set the contents of the 'li' element created above 
    node.innerHTML = `
    <input id="${todo.id}" type="checkbox"/>
    <label for="${todo.id}" class="tick js-tick"></label>
    <span>${todo.text}</span>
    <button class="delete-todo js-delete-todo">
    <svg><use href="#delete-icon"></use></svg>
    </button>
    `;

    //if the item already exists in the DOM
    if(item){
        //replace it
        list.replaceChild(node, item);
    } else {
        //append the element to the DOM as the last child of the element referenced by the 'list' variable
        list.append(node);
    }
}

//function to create a new list object based on text that was entered in input and push it into the todoItems array
function addTodo(text) {
    const todo = {
        text,
        checked: false,
        id: Date.now(),
    };

    todoItems.push(todo);
    renderTodo(todo);
}

function toggleDone (key){
    //findIndex is an array method that returns the position of an element in the array
    const index = todoItems.findIndex(item => item.id === Number(key));
    //locate the todo item in the todoItems array and set its checked property to opposite
    todoItems[index].checked = !todoItems[index].checked;
    renderTodo(todoItems[index]);
}

function deleteTodo(key) {
    //find the corresponding todo object in the todoItems array
    const index = todoItems.findIndex(item => item.id === Number(key));
    //create a new object with properties of the current todo item and a 'deleted' property which is set to true
    const  todo = {
        deleted: true,
        ...todoItems[index],
    };

    //remove the todo item from the array by filtering it out
    todoItems = todoItems.filter(item => item.id !== Number(key));
    renderTodo(todo);
}

//select the form element
const form = document.querySelector('.js-form');
//add a submit event listener
form.addEventListener('submit', event => {
    //prevent page refresh on submit
    event.preventDefault();
    //select the text input
    const input = document.querySelector('.js-todo-input');

    //get the value of the input and remove whitespace
    const text = input.value.trim();
    if (text !== '') {
        addTodo(text);
        input.value = '';
        input.focus();
    }
});

//select the entire list
const list = document.querySelector('.js-todo-list');
//Add a click event listener to the list and its children
list.addEventListener('click', event => {
    if(event.target.classList.contains('js-tick')) {
        const itemKey = event.target.parentElement.dataset.key;
        toggleDone(itemKey);
    }

    //check for deletion
    if(event.target.classList.contains('js-delete-todo')) {
        const itemKey = event.target.parentElement.dataset.key;
        deleteTodo(itemKey);
    }
});

//to render existing todo list when page is loaded
document.addEventListener('DOMContentLoaded', () => {
    const ref = localStorage.getItem('todoItems  ');
    if(ref) {
        todoItems = JSON.parse(ref);
        todoItems.forEach(t => {
            renderTodo(t);
        });
    }
});