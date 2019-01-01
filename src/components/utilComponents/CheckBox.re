let component = ReasonReact.statelessComponent("checkbox");

let str = ReasonReact.string;

let checkbox = (color, checked) => {
    <div 
            className="Checkbox"
            style=(
                ReactDOMRe.Style.make(
                    ~backgroundColor="white",
                    ~fontFamily="sans-serif",
                    ~color=color,
                    ~height="2vh",
                    ~width="2vw",
                    ~border="2px solid " ++ color,
                    ~fontSize="2vh",
                    ~textAlign="center",
                    ~marginTop="3px",
                    ()
                )
            )
    >{checked ? str("X") : str("")}</div>
        
}

let make = (~color, ~checked, _) => {
    ...component,
    render: (_self) => {
        checkbox(color, checked);
    }
}