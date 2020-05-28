// Async await - Funcion agregada en la version ES8 de JS

// Nuestra funcion con Promesa
const helloWorld = () => {
    return new Promise((resolve, reject) => {
        (true)  // If Ternario
        ? setTimeout(() => resolve('Hello World', 3000))
        : reject(new Error('Test Error'));
    });
};

// Definimos una funcion de tipo async
const helloAsync = async () => { // Implementamos async
    const hello = await helloWorld(); // Hacemos que espere la resolucion
    // de la promesa antes de definirle su valor
    console.log(hello);
};

helloAsync(); // Funcion async await

// ===

// Otra funcion async await con try catch para errores
const otherFunction = async () => {
    try {
        const hello = await helloWorld();
        console.log(hello);
    } catch (e) {
        console.log(e);
    }
};

otherFunction();