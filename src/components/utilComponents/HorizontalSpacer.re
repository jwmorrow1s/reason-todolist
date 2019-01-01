let component = ReasonReact.statelessComponent("horizontalSpacer");

let horizontalSpacer(size) =     
    <div 
        style=(
            ReactDOMRe.Style.make(
            ~width=size++"px", ()
            )
        )
/>

let make = (~size, _) => {
    ...component,
    render: (_) => horizontalSpacer(size)
};