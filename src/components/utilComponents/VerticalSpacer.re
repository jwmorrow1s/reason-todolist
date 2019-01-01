let component = ReasonReact.statelessComponent("verticalSpacer");

type alignment = 
  | Vertical
  | Horizontal;

let verticalSpacer(size) =     
    <div 
        style=(
            ReactDOMRe.Style.make(
            ~height=size++"px", ()
            )
        )
/>

let make = (~size, _) => {
    ...component,
    render: (_) => verticalSpacer(size)
};