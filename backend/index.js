const express = require("express")
const app = express()
const cors = require("cors")
const axios = require("axios");
app.use(express.json())
app.use(cors({origin: true}))

app.post("/authenticate", async (req, res) => {
    const { username } = req.body;
    // Get or create user on Chat Engine!
    try {
      const r = await axios.put(
        "https://api.chatengine.io/users/",
        { username: username, secret: username, first_name: username },
        { headers: { "Private-Key": "3c5ea22e-3d20-49c3-8913-9e78e2ae28cb" } }
      );
      return res.status(r.status).json(r.data);
    } catch (e) {
      return res.status(e.response.status).json(e.response.data);
    }
})

app.listen(5000)