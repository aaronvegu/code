@extends ('layout')

@section ('bodyTag')
<body class="subpage">
@endsection

@section ('main')
<!-- Three -->
<section id="three" class="wrapper">
	<div class="inner">
		<header class="align-center">
			<h2> {{ $articles->title }} </h2>
			<p> {{ $articles->excerpt }} </p>
		</header>
		<p> {{ $articles->body }} </p>
	</div>
</section>
@endsection