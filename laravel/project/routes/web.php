<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/


Route::get('/', function () {
    $articles = App\Article::latest()->take(3)->get();
    return view('welcome', [
        'articles' => $articles
    ]);
});

Route::get('/main', function() {
	return view('main', [
		'name' => request('name')
	]);
});

/*
Route::get('/posts/{post}', function ($post) { // Declaramos el paso de wildcard, y en la funcion indicamos que pasara como parametro la wildcard recibida en la ruta
    $response = [ // Creamos un array asociativo que contendra info que sera asociada conforme a la wildcard que es pasada como parametro a la funcion que lo contiene
    	'post-1' => 'Hola, este es el primer post que escribo :)',
        'post-2' => 'Este es el segundo post, empiezo a tomarle sentido.'
    ];
    
    if (! array_key_exists($post, $response)) { // Creamos una condicion donde de no encontrar la key asociada en la wildcard, mandar un error 404 y un mensaje personalizado a traves de la funcion de Laravel abort()
        abort(404, 'Lo siento, el post que buscas no existe.');
    };
    
    return view('posts', [ // Retornamos la vista deseada y pasamos la info como segundo parametros a traves de un array. Donde la variable la llamamos post y toma el valor del array response segun su id que recibe de la wildcard
    	'post' => $response[$post]
    ]);
});
*/

Route::get('/articles', function() {
    return view('articles');
});

Route::get('/elements', function() {
    return view('elements');
});

Route::get('/articles', 'ArticlesController@index');

Route::post('/articles', 'ArticlesController@store');

Route::get('/articles/create', 'ArticlesController@create');

Route::get('/articles/{article}', 'ArticlesController@show');

Route::get('/articles/{article}/edit', 'ArticlesController@edit');

Route::put('articles/{article}', 'ArticlesController@update');
