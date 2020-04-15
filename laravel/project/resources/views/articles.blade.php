@extends ('layout')

@section ('bodyTag')
<body class="subpage">
@endsection

@section ('main')
<!-- Three -->
<section id="three" class="wrapper">
	<div class="inner">
		<header class="align-center">
			<h2>Our Articles</h2>
		</header>
		<div class="flex flex-2">

			@foreach ($articles as $article)
			<article style="margin-bottom: 50px;">
				<div class="image fit">
					<img src="/images/pic01.jpg" alt="Pic 01" />
				</div>
				<header>
					<h3> {{ $article->title }} </h3>
				</header>
				<p> {{ $article->excerpt }} </p>
				<footer>
					<a href="articles/ {{ $article->id }} " class="button special">More</a>
				</footer>
			</article>
			@endforeach

		</div>
	</div>
</section>
@endsection