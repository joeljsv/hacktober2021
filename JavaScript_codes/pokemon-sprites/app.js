const container = document.querySelector(".container");

// alert('Reload 2-3 times for Best Experience!!');

// https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png

// Using PokeAPI in this Branch

//https://pokeapi.co/api/v2/pokemon-form/${i}/

async function get_data(poke_url) {
  const response = await fetch(poke_url);
  const data = await response.json();
  return data;
}

for (let i = 1; i <= 151; i++) {
  const div = document.createElement("div");
  const img = document.createElement("img");
  const span = document.createElement("span");

  get_data(`https://pokeapi.co/api/v2/pokemon-form/${i}/`).then((data) => {
   // console.log(data);
    img.src = `${data.sprites.front_default}`;
    span.innerText = `${(data.name).charAt(0).toUpperCase()}${(data.name).slice(1)}`;
    div.classList.add("align");

    div.appendChild(img);
    div.appendChild(span);
    container.appendChild(div);
    
  })
}
