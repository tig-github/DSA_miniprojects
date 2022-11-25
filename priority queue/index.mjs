// fetch content from backend
import { PriorityQueue } from './heap-module/priorityqueue.js';

// no arrow function due to older browser support
function init(){
    //const pq = require('./heap-module/priorityqueue.js');
    let Q = PriorityQueue();
}

function addBook(){
    alert('Book added!');
    console.log(Q);
}