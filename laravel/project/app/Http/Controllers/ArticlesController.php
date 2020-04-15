<?php

namespace App\Http\Controllers;

use App\Article;
use Illuminate\Http\Request;

class ArticlesController extends Controller
{

	public function index()
	{
		// Nos permite crear una lista de los recursos

		$articles = Article::latest()->get();

		return view('articles', ['articles' => $articles]);
	}

    public function show(Article $article)
    {
    	// Nos muestra un recurso especifico
    	return view('articles.show', ['articles' => $article]);
    }

    public function create()
    {
    	return view('articles.create');
    }

    public function store()
    {
        // Nos guarda la informacion del nuevo articulo
        
        Article::create($this->validateArticle());

        return redirect('/articles');
    }

    public function edit(Article $article)
    {
    	return view('articles.edit', ['article' => $article]);
    }

    public function update(Article $article)
    {
    	// Guarda la informacion del recurso editado

        $article->update($this->validateArticle());

        return redirect('/articles/' . $article->id);
    }

    public function destroy()
    {
    	// Elimina el recurso deseado
    }

    protected function validateArticle() 
    {
        // Valida los atributos del formulario
        return request()->validate([
            'title' => ['required', 'min:3', 'max:255'],
            'excerpt' => 'required',
            'body' => 'required'
        ]);
    }
}
