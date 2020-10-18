[@bs.val] external document: Dom.document = "document";
[@bs.val] external setTimeout: (unit => unit, int) => unit = "setTimeout";
[@bs.get] external getStyle: Dom.element => Dom.cssStyleDeclaration = "style";

let makeDots = (numDots, element) => {
    Random.self_init();

    let dotColors = [|"rgba(29, 14, 190, 0.5)", "rgba(162, 165, 252, 0.5)", "rgba(98, 125, 152, 0.5)"|];

    let elementStyle = getStyle(element);

    let createDot = () => {
        /*
        Get randomized values for the Dot's initial position, size, transform, and 
        animation duration/delay and then format them into the proper strings.
        */
        let top = ((Random.int(110) - 10) -> string_of_int) ++ "%";
        let left = ((Random.int(110) - 10) -> string_of_int) ++ "%";

        let size = ((Random.int(9) + 10) -> string_of_int) ++ "px";

        let x = ((Random.int(71) + 30) -> string_of_int) ++ "px";
        let y = ((Random.int(71) + 30) -> string_of_int) ++ "px";
        let transformOrigin = x ++ " " ++ y;

        let animationDuration = ((Random.int(15) + 10) -> string_of_int) ++ "s";
        let animationDelay = ((Random.int(8) * -1) -> string_of_int) ++ "s";
        let animation = "orbit " ++ animationDuration ++ " linear " ++ animationDelay ++ " infinite";

        let color = Array.length(dotColors) -> Random.int |> Array.get(dotColors);

        /*
        Create the dot and set the style string created above.
        */
        let dot = Webapi.Dom.Document.createElement("div", document);
        Webapi.Dom.Element.setClassName(dot, "dot");

        let style = getStyle(dot);
        Webapi.Dom.CssStyleDeclaration.setProperty("top", top, "", style);
        Webapi.Dom.CssStyleDeclaration.setProperty("left", left, "", style);

        Webapi.Dom.CssStyleDeclaration.setProperty("width", size, "", style);
        Webapi.Dom.CssStyleDeclaration.setProperty("height", size, "", style);

        Webapi.Dom.CssStyleDeclaration.setProperty("transform-origin", transformOrigin, "", style);
        Webapi.Dom.CssStyleDeclaration.setProperty("animation", animation, "", style);

        Webapi.Dom.CssStyleDeclaration.setProperty("background-color", color, "", style);

        Webapi.Dom.Element.appendChild(dot, element);
    };

    for (_ in 0 to numDots) {
        setTimeout(createDot, 0);
    };
}