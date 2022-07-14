exports.get404 = (req, res, next) => {
	// res.status(404).sendFile(path.join(__dirname, "views", "404.html"));
	// res.status(404).render('404');
	// res.status(404).render("404.ejs", {
	// 	pageTitle: "Page Not Found!"
	// }); // using dynamic layout
	res.status(404).render("404.ejs", {
		pageTitle: "Page Not Found!",
        path: "/404"
	}); // using dynamic layout
}