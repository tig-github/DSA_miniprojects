import { PriorityQueue } from './priorityqueue.js';

// initializes reading list
export const init = () => {
    let readingList = new PriorityQueue();
    console.log('l')
}

const addBook = (readingList, book) => {
    readingList.enqueue(book);
}

const getBook = (readingList) => {
    return readingList.dequeue();
}