import * as http from 'http';
import { init } from './modules/index.js';

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.writeHead(200, {'Content-Type': 'text/html'});
  res.end('Hello World');
  console.log('w');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});