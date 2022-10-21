// import { PriorityQueue } from './priorityqueue.js';
PriorityQueue = require('priorityqueue.js');

// initializes reading list
const init = () => {
    let readingList = new PriorityQueue();
    console.log('l')
}

const addBook = (readingList, book) => {
    readingList.enqueue(book);
}

const getBook = (readingList) => {
    return readingList.dequeue();
}