<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateArticlesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('articles', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->unsignedBigInteger('user_id');
            $table->string('title');
            $table->text('excerpt');
            $table->text('body');
            $table->timestamps();
            // Agregamos nuestra Llave Foranea
            $table->foreign('user_id')  // Nombre de la columna que sera foranea en la tabla actual
                ->references('id')      // Nombre de la columna a la que referencia la llave foranea (primary)
                ->on('users')           // Nombre de la tabla donde se encuentra la referencia
                ->onDelete('cascade');  // Si se eliminan datos, eliminar en cascada para evitar datos huerfanos
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('articles');
    }
}
