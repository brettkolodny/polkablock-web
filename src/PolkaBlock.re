type blockQuery = {
    hash: string,
    number: string,
};

[@bs.module "./blockInfo"] external getBlockInfo: blockQuery => Js.Promise.t('a) = "getBlockInfo";
[@bs.val] external document: Dom.document = "document";
[@bs.send.pipe: Dom.document] external getElementById: string => Dom.element = "getElementById";
[@bs.get] external getValue: Dom.element => string = "value";

let getBlockInfoPromise = (hash, setter) => {
    let _ = getBlockInfo(hash)
    |> Js.Promise.then_(value => {
        setter(_ => Some(value));
        Js.Promise.resolve(Some(value));
        })
    |> Js.Promise.catch(err => {
        Js.log(err);
        Js.Promise.resolve(None);
    });
};

[@react.component]
let make = () => {
    let (info, setInfo) = React.useState(_ => None);

    let search = () => {
        let hash = getElementById("hash-input", document) -> getValue;
        let number = getElementById("number-input", document) -> getValue;

        if (hash != "") {
            getBlockInfoPromise({hash: hash, number: ""}, setInfo);
        } else if (number != "") {
            getBlockInfoPromise({hash: "", number: number}, setInfo);
        } else {
            getBlockInfoPromise({hash: "", number: ""}, setInfo);
        };
    };

    <div id="content">
        <div id="title">{React.string("Polkablock")}</div>
        <div id="search-inputs">
            <input id="hash-input" placeholder="hash" />
            <input id="number-input" placeholder="number" />
        </div>
        <div id="search-button" onClick={_ => search()}>{React.string("Search")}</div>

        {
            switch (info) {
            | Some(v) => <Block blockInfo=v />
            | _ => <Info />
            };
        }
    </div>
};