@extends ('layout')

@section ('content')
	<h2>Hello World</h2>
	<hr>
	<p>{{ $post->body }}</p>
@endsection