const fs = require('fs'); // For file manipulation
const crypto = require('crypto'); // For generating the file name
const express = require('express'); // For creating the REST API
const { exec } = require('child_process'); // For running the `echo` command

const app = express();

var RateLimit = require('express-rate-limit');
var limiter = new RateLimit({
  windowMs: 1*60*1000, // 1 minute
  max: 10
});

// apply rate limiter to all requests
app.use(limiter);


app.get('/echo', (req, res) => {
  // Get the query from the request
  const query = req.query.q.replace(/:/g, ';');

  // Generate a file name based on the hash of the query
  const fileName = crypto.createHash('sha256').update(query).digest('hex');

  // Write the query to the file
  fs.writeFileSync(fileName, query);

  // Run the `echo` command and read the output
  exec(`../main --debug --file ./${fileName}`, (err, stdout, stderr) => {
    if (err) {
      // If there was an error, return the error message and a non-zero exit code
      res.send({ output: stderr, code: err.code });
    } else {
      // If the command ran successfully, return the output and a zero exit code
      // Replace semicolons with colons and newline characters with <br>
      const output = stdout.replace(/\n/g, '<br>');
      res.send({ output, code: 0 });

      // Delete the file after the response is sent
      fs.unlinkSync(fileName);
    }
  });
});

app.listen(3000, () => {
  console.log('Echo API listening on port 3000!');
});

