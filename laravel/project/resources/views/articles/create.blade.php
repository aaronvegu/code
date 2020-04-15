@extends('layout')

@section ('bodyTag')
	<body class="subpage">
@endsection

@section('main')
	<div id="wrapper" style="margin: 50px;">
		<div id="page" class="container">
			<h1>New Article</h1>

			<form method="POST" action="/articles">
				@csrf
				
				<div class="field">
					<label class="label" for="title">Titulo</label>	

					<div class="control">
						<input type="text" class="input @error('title')	is-invalid @enderror" name="title" id="title" value="{{ @old('title') }}">

						@error('title')
							<p class="invalid-feedback">{{ $errors->first('title') }}</p>
						@enderror

					</div>
				</div>
				<div class="field">
					<label class="label" for="excerpt">Resumen</label>	

					<div class="control">
						<textarea class="textarea" name="excerpt" id="excerpt" required>{{ @old('excerpt') }}</textarea>
					</div>
				</div>
				<div class="field">
					<label class="label" for="body">Cuerpo del Articulo</label>	

					<div class="control">
						<textarea class="textarea" name="body" id="body" required>{{ @old('body') }}</textarea>
					</div>
				</div>
				<div class="field is-grouped">

					<div class="control" style="margin-top: 20px;">
						<button class="button is-link" type="submit">Enviar</button>
					</div>
				</div>

			</form>
		</div>
	</div>
@endsection