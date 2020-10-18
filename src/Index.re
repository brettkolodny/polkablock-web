[@bs.val] external document: Dom.document = "document";
[@bs.send.pipe: Dom.document] external getElementById: string => Dom.element = "getElementById";

switch (ReactDOM.querySelector("#root")) {
| Some(root) => ReactDOM.render(
    <div>
        <div id="dots"></div>
        <PolkaBlock />
    </div>
    ,root)
| None => ()
};

Dots.makeDots(200, getElementById("dots", document));