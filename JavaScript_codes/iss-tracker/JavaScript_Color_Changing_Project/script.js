let colors = ["red", "blue", "green", "orange", "purple", "black", "yellow"];

let button = document.getElementById("button");

button.addEventListener("click", function () {
  let index = parseInt(Math.random() * colors.length + 1);
  let colorDiv = document.getElementById("colorDiv");
  colorDiv.style.background = `${colors[index]}`;
});
