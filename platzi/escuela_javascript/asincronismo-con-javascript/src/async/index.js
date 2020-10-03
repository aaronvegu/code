// Async-Await nos permite obtener control sobre nuestro codigo,
// haciendo que el condigo asincrono se comporte como sicrono

const doSomethingAsync = () => {
    return new Promise((resolve, reject) => { //Promesa verdadera
        (true)
            ? setTimeout(() => resolve('Do Something Async'), 3000)
            : reject(new Error('Test Error'))
    });
}

// Ejecucion de promeso en funcion async
const doSomething = async () => {
    const something = await doSomethingAsync()
    // Estamos diciendo que espere a que se realice nuestra
    // promesa asincrona antes de continuar con la ejecucion
    console.log(something);
    // Despues de resolver la promesa, mostramos en consola
    // lo que nos devolvio nuestra promesa que guardamos en
    // something
}

console.log('Before');
doSomething();
console.log('After');

// Con manejo de errores
const anotherFunction = async () => {
    try {
        const something = await doSomethingAsync();
        console.log(something);
    } catch (error) {
        console.error(error);
    }
}

console.log('Before I');
anotherFunction();
console.log('After I');