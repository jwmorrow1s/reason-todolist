let component = ReasonReact.statelessComponent("checkbox");

let str = ReasonReact.string;

let checkbox = (color, checked) => {
    <div 
            className="Checkbox"
            style=(
                ReactDOMRe.Style.make(
                    ~backgroundColor="white",
                    ~fontFamily="sans-serif",
                    ~textShadow="none",
                    ~color=color,
                    ~height="25px",
                    ~width="25px",
                    ~border="2px solid " ++ color,
                    ~fontSize="25px",
                    ~textAlign="center",
                    ~marginTop="4px",
                    ~marginLeft="4px",
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