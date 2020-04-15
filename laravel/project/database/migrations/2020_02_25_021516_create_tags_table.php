<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateTagsTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('tags', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('name');
            $table->timestamps();
        });

        Schema::create('article_tag', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('article_id');   // Creamos columnas que contendran
            $table->unsignedBigInteger('tag_id');       // a las llaves foraneas
            $table->timestamps();

            $table->unique(['article_id', 'tag_id']);   // Indicamos que la relacion debe ser unica
            $table->foreign('article_id')->references('id')->on('articles')->onDelete('cascade');   // Declaramos
            $table->foreign('tag_id')->references('id')->on('tags')->onDelete('cascade');       // Llaves Foraneas
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('tags');
    }
}
