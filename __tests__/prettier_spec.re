open Jest;

let () =
  describe(
    "prettier",
    ExpectJs.(
      () => {

        let core = {|Don't touch me. Because I'm already pretty. That's all folks.|};

        let structured = {|<article>
<h1>Title</h1>
<p>Some introduction ...</p>
<section>
<h2>Section 1 title</h2>
<p>Some paragraph ...</p>
<section>
<h3>Subsection title</h3>
<p>Some paragraph ...</p>
</section>
</section>
<section>
<h2>Section 2 title</h2>
<p>Some paragraph ...</p>
<p>Another paragraph ...</p>
</section>
</article>|};

        let formatted = {|<article>
  <h1>Title</h1>
  <p>Some introduction ...</p>
  <section>
    <h2>Section 1 title</h2>
    <p>Some paragraph ...</p>
    <section>
      <h3>Subsection title</h3>
      <p>Some paragraph ...</p>
    </section>
  </section>
  <section>
    <h2>Section 2 title</h2>
    <p>Some paragraph ...</p>
    <p>Another paragraph ...</p>
  </section>
</article>
|};

        test("#format(html)", () =>
          expect(Prettier.format(core, { "parser": "html" }))
          |> toBe(core ++ "\n")
        );

        test("#format(html)", () =>
          expect(Prettier.format(structured, { "parser": "html" }))
          |> toBe(formatted)
        );
      }
    ),
  );
