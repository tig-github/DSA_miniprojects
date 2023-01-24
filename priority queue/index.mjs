// fetch content from backend
import { PriorityQueue } from './heap-module/priorityqueue.js';
// no arrow function due to older browser support


let Q = pq.PriorityQueue('max');

//window.onload = init();

const addBook = (book = 'newbook', priority = 1) => {
    alert('Book added!');
    Q.enqueue(book, priority);
}
addButton = document.getElementById('add');
addButton.addEventListener("click", addBook);

const getBook = () => {
    alert(Q.top());
    return Q.top();
}
addButton = document.getElementById('get');
addButton.addEventListener("click", getBook);

const removeBook = () => {
    Q.dequeue();
}
addButton = document.getElementById('remove');
addButton.addEventListener("click", getBook);

const clearQueue = () => {
    Q = PriorityQueue('max');
}
addButton = document.getElementById('clear');
addButton.addEventListener("click", getBook);
