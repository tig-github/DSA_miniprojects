import * as http from 'http';
import * as fs from 'fs';
import { PriorityQueue } from './heap-module/priorityqueue.js';
// const http = require('http');
// const pq = require('./heap-module/priorityqueue.js');


// const hostname = '127.0.0.1';
// const port = 3000;

// //routes
// const server = http.createServer((req, res) => {
//   res.statusCode = 200;
//   res.writeHead(200, {'Content-Type': 'text/html'});
//   res.end('Hello World');
//   console.log('w');
// });

// server.listen(port, hostname, () => {
//   console.log(`Server running at http://${hostname}:${port}/`);
// });

let html;
let css;
// let js;

fs.readFile('../index.html', function (err, data) {
  if (err) {
    throw err;
  }
  html = data;
});
fs.readFile('../index.css', function (err, data) {
  if (err) {
    throw err;
  }
  css = data;
});
// fs.readFile('../index.mjs', function (err, data) {
//   if (err) {
//     throw err;
//   }
//   js = data;
// });

http.createServer((req, res) => {
  res.statusCode = 200;
if(req.url.indexOf('.css') != -1){
   res.writeHead(200, {'Content-Type': 'text/css'});
   res.write(css);
   res.end();
   return;
  }
// if(req.url.indexOf('index.mjs') != -1){
//    res.writeHead(200, {'Content-Type': 'text/javascript'});
//    res.write(js);
//    res.end();
//    return;
//   }
res.writeHeader(200, {"Content-Type": "text/html"});
  res.write(html);
  res.end();
}).listen(3000);