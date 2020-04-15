<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Post;

class PostsController extends Controller
{
    public function show($slug) // El valor tomado de la wildcard desde routes/web.php lo llamamos $slug
    {
    	
    	$post = Post::where('slug', $slug)->firstOrFail();

    	// dd($post); // Para inspecionar variable

    	/* Obtencion de datos sin BBDD
    	$response = [ // Creamos un array asociativo que contendra info que sera asociada conforme a la wildcard que es pasada como parametro a la funcion que lo contiene
    	'post-1' => 'Hola, este es el primer post que escribo :)',
        'post-2' => 'Este es el segundo post, empiezo a tomarle sentido.'
    	];
    	*/
 
    	/*
	    if (! array_key_exists($slug, $response)) { // Creamos una condicion donde de no encontrar la key asociada en la wildcard, mandar un error 404 y un mensaje personalizado a traves de la funcion de Laravel abort()
	        abort(404, 'Lo siento, el post que buscas no existe.');
	    };
	    */

	    return view('posts', [ // Retornamos la vista deseada y pasamos la info como segundo parametros a traves de un array. Donde la variable la llamamos post y toma el valor del array response segun su id que recibe de la wildcard
	    	'post' => $post
	    ]);
	}
}
